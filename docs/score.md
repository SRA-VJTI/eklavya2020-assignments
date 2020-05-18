# Eklavya Round 1 Selected Teams

[Marks Distribution](marks_distribution.md)

{% assign sorted = site.data.scoreboard | sort: "Score" | reverse %}

| Rank | Team Name         | Assignment 1 | Assignment 2 | Assignment 3 | Assignment 4 | Score |  
|      |                   |      50      |      100     |      100     |      150     |       |  
|:----:|-------------------|:------------:|:------------:|:------------:|:------------:|:-----:|{% for team in sorted %}{% if forloop.index <= 30 %}
| {{ forloop.index }} |{{ team.TeamName }} | {{ team.Assignment1 }} | {{ team.Assignment2 }}  | {{ team.Assignment3 }}  | {{ team.Assignment4 }}  | {{ team.Score }}  |{% endif %}{% endfor %}

[Go back](index.md)

